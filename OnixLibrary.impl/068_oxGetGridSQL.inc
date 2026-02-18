function oxGetGridSQL(gridName: String): String;
var strings: TStrings;
begin
    with TcxGridDBTableView(AresFindComponent(gridName, OwnerForm)) do
    begin
        strings := TdlDataSource(DataController.DataSet.DataSource).SQL;
        if strings <> nil then
        begin
            Result := strings.Text;
        end;
    end;
end;




