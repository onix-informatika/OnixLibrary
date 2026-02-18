function oxNavigator(name: String = 'bMenuDBNavigator'): TNavigator3;
begin
    Result := TNavigator3(OwnerForm.FindComponent(name));
end;




