procedure oxPrintComponent(component: TComponent; prefix: String = '');
var index: Integer;
begin
    if component <> nil then
    begin
        _macro.EventLogAdd(Format('%s%s', [prefix, component.Name]));
        for index := 0 to component.ComponentCount - 1 do
        begin
            oxPrintComponent(component.Components[index], prefix + #9);
        end; 
    end else
    begin
        _macro.EventLogAdd(Format('%s%s', [prefix, 'Komponenta nije postavljena']));
    end;   
end;




