procedure oxLogAresVariables();
var variableStrings: TStringList;
    varString: String;
begin
    variableStrings := TStringList.Create();    
    Ares.Variables.SaveToStrings(variableStrings);
    
    for varString in variableStrings do begin
        // ovo ispisuje svaki redak
        _macro.EventLogAdd(varString);
    end;
end;




