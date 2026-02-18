procedure Versioned(stepId: integer; procName: String; procVersionInt: integer; objectType: String; objectName: String);
var procFirstLine: String;
    originalProcFirstLine: String;
    oldProcName: String;
    method: String;
    procToDelete: String;
    procVersion: String;
    stepSQL:String;
begin
    procFirstLine := oxSQLExpWithParams('exec sp_helptext :p0', [procName]);
    
    procVersion := 'override' + IntToStr(procVersionInt);
    procName := procName;
    oldProcName := procName + 'Original';
    method := 'CREATE';
    
    Ares.Variables['procVersion'] := procVersion;
    Ares.Variables['procName'] := procName;
    Ares.Variables['oldProcName'] := oldProcName;
    Ares.Variables['method'] := method;
     
    if procFirstLine.IndexOf('override') = 0 then
    begin
        _macro.EventLogAdd('Ne postoji naĹˇa override procedura, ako postoji original briĹˇem ga i radim override proceduru i backup');
        
        originalProcFirstLine := oxSQLExpWithParams('exec sp_helptext :p0', [oldProcName]);
        
        if originalProcFirstLine = '' then
        begin
            _macro.EventLogAdd('Ne postoji originalna procedura, mogu napraviti backup proceduru i izraditi override proceduru, ne briĹˇem niĹˇta, nastavljam normalno');
        end else
        begin
            _macro.EventLogAdd('Postoji originalna procedura, briĹˇem je, i nastavljam');
            procToDelete := oldProcName;
            oxSQLExp('drop ' + objectType + ' ' + objectName);
        end;
                    
        oxSQLExpWithParams('EXEC SP_RENAME :p0, :p1', [procName, oldProcName]);
        // postavljanje
        stepSQL := oxSQLStepWithAresVariablesApplied(stepId);
        oxSQLExp(stepSQL);
    end else
    begin
        _macro.EventLogAdd('Postoji naĹˇa override procedura, provjeravam ako je verzija dobra');
        
        if procFirstLine.IndexOf(procVersion) = 0 then
        begin
            _macro.EventLogAdd('Kriva verzija override procedure: ''' + COPY(procFirstLine, procFirstLine.IndexOf('override') + 1, LENGTH(procFirstLine) - 2) + ''', traĹľio sam verziju: ''' +  procVersion + ''', radim alter, original ne diram');
            method := 'ALTER'; // samo promjeni staru proceduru na novu verziju
            // postavljanje
            Ares.Variables['method'] := method;
            stepSQL := oxSQLStepWithAresVariablesApplied(stepId);
            oxSQLExp(stepSQL);
        end else
        begin
            _macro.EventLogAdd('Verzija procedure je ok, ne diram niĹˇta');
        end;
    end;
end;





