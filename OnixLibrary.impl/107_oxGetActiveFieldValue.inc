function oxGetActiveFieldValue(gridOrDSName: string; fieldName: String): String;
var columnIndex: Integer;
    column: TcxGridColumn;
begin
    with oxGetGrid(gridOrDSName) do
    begin                
        column := GetColumnByFieldName(fieldName);
        if column <> nil then
        begin
            columnIndex := column.Index;
            _macro.EventLogAdd('Column index: ' + inttostr(columnIndex));
            Result := Controller.FocusedRow.Values[columnIndex];
        end else begin
            showmessage(fieldName + ' ne postoji na ' + gridOrDSName + '!');
        end;
    end;
end;




