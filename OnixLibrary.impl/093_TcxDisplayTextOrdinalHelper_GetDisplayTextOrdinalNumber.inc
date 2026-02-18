procedure TcxDisplayTextOrdinalHelper.GetDisplayTextOrdinalNumber(Sender: TcxCustomGridTableView; ARecord: TcxCustomGridRecord; var AText: String);
var row: Integer;
begin
    //row := Sender.DataController.GetRowIndexByRecordIndex(ARecord.RecordIndex, False);
    //AText := IntToStr(row + 1);
    AText := IntToStr(ARecord.Index + 1);
end;




