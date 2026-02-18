procedure TCheckboxListOnix.AddFromDataSet(Dataset: TdlDataSet);
begin
  if not Dataset.Active then
  begin
    Dataset.open;
  end;
  Dataset.First;
  while not Dataset.EOF do
  begin
    // Make sure the dataset has at least three fields
    if Dataset.Fields.Count < 3 then
      raise Exception.Create('Dataset has less than three fields');

    self.Add(Dataset.Fields[0].AsString, 
             Dataset.Fields[1].AsString, 
             Dataset.Fields[2].AsString = '1');
             
    Dataset.Next;
  end;
end;





