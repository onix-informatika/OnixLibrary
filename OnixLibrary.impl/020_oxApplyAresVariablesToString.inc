function oxApplyAresVariablesToString(s: String): String;
var variableStrings: TStringList;
    varString: String;
    split: array of string;
    varName, varValue: String;
    i: Integer;
begin
    variableStrings := TStringList.Create();    
    Ares.Variables.SaveToStrings(variableStrings);
    
    for varString in variableStrings do begin
        _macro.EventLogAdd(varString);
        split := varString.split('=');
        
        if Length(split) > 1 then
        begin
            varName := split[0].Trim;
            varValue := split[1];
        
            // Concatenate remaining parts if there are more than two parts after the split
            for i := 2 to High(split) do
            begin
                varValue := varValue + '=' + split[i];
            end;
          
            s := StringReplace(s, '#' + varName + '#', varValue.Trim, [rfReplaceAll]);
        end;
    end;                                     
    
    result := s;
end;




