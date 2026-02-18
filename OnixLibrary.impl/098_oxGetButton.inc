function oxGetButton(button: String): TcxButton;
begin
    Result := TcxButton(AresFindComponent(button, OwnerForm));
end;




