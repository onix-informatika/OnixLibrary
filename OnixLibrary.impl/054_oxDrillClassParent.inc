procedure oxDrillClassParent(obj: TObject); 
var
  cls: TClass;
begin
  cls := obj.ClassType;
  _macro.EventLogAdd(cls.ClassName);
  if Assigned(cls.ClassParent) then
    oxDrillClassParent(cls.ClassParent.NewInstance);
end;




