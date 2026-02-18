function oxAddColumn(gridName: String; columnCaption: String; columnFieldName: String; width: integer = 50): TcxGridDBColumn;
begin
    with TcxGridDBTableView(AresFindComponent(gridName, OwnerForm)) do
    begin      
        Result := CreateColumn();
        Result.Caption := columnCaption;
        Result.Name := oxOnlyASCIILetterAndNumbers(gridName + columnFieldName);
        Result.DataBinding.FieldName := columnFieldName;
        Result.Width := width;
    end;
end;




