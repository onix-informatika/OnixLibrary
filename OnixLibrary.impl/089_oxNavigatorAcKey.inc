function oxNavigatorAcKey(name: String = 'bMenuDBNavigator'): String;
var comp: TComponent;
begin
    comp := OwnerForm.FindComponent(name);
    if not assigned(comp) then
    begin
        showmessage(name + ' nije ispravan navigator! Ne postoji...');
    end else
    begin
        Result := oxNavigator(name).datasource.dataset.FieldByName('ackey').asstring;
    end;
end;




