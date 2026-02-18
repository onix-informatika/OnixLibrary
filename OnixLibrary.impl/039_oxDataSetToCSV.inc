procedure oxDataSetToCSV(DataSet: TdlDataSet; const FileName: string; const Delimiter: string = ';'; const QuoteEverything: boolean = false);
var
  StringList: TStringList;
  Field: TField;                                  
  Line: string;
  i: Integer;
begin
  StringList := TStringList.Create;
  try                              
    try
    DataSet.First;

    // Write column headers
    Line := '';
    for Field in DataSet.Fields do
    begin
      if Line <> '' then
        Line := Line + Delimiter;
      Line := Line + Field.FieldName;
    end;
    StringList.Add(Line);

    // Write data
    while not DataSet.Eof do
    begin
      Line := '';
      for i := 0 to DataSet.FieldCount - 1 do
      begin
        if Line <> '' then
          Line := Line + Delimiter;
        if QuoteEveryThing then
        begin
            Line := Line + QuotedStr(DataSet.Fields[i].AsString);
        end else
        begin
            Line := Line + DataSet.Fields[i].AsString;
        end;
      end;
      StringList.Add(Line);
      DataSet.Next;
    end;
    StringList.SaveToFile(FileName);
    except on E:Exception do
        begin
            _macro.EventLogAdd('Error: ' + E.message);
        end
    end;
  finally
    StringList.Free;
  end;
end;




