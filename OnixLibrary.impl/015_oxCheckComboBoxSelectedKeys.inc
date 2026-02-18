function oxCheckComboBoxSelectedKeys(cbx: TcxCheckComboBox): TStringList;
var
  i: Integer;
  Params: TStringList;
begin
  Params := TStringList.Create;

    for i := 0 to cbx.Properties.Items.Count - 1 do
    begin
      if cbx.States[i] = cbsChecked then
      begin
        Params.Add(cbx.Properties.Items[i].Tag.ToString);
      end;
    end;
  
  Result := Params;
end;




