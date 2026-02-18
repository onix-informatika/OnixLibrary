procedure oxLogElementClassname(elementName: String);
var obj: TObject;
begin
    obj := Ares.FindComponent(elementName);
    if obj <> nil then oxLogObjectClassName(obj, elementName)
    else _macro.EventLogAdd(Format('Ne postoji element: "%s"', [elementName]));
end;




