procedure oxAddDefToNavigator(def: String; navigator: String = 'bMenuDBNavigator'; atIndex: Integer = -1);
var nav: TNavigator3;
    sl: TStringList;
begin
    nav := oxNavigator(navigator);
    sl := TStringList.Create;
    sl.CommaText := nav.LookupSelected.CommaText;
    nav.LookupSelected.Clear;
    if atIndex = -1 then
        sl.Add(def)
    else
        sl.Insert(atIndex, def);
    nav.LookupSelected := sl;
end;




