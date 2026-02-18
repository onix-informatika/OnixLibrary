procedure oxDrillClassParentUpwards(obj: TWinControl); 
var
    cls: TWinControl;
begin
    _macro.EventLogAdd('Parents upwards from ' + obj.Name);

    cls := obj.Parent;
    
    while cls <> nil do
    begin                                
        _macro.EventLogAdd(cls.Name);
        cls := cls.Parent;
    end; 
end;




