function oxSQLBlobToStream(sql: string; params: array of Variant): TStream;
var
  i: Integer;
  dataSet: TdlDataSet;
  blobFieldName: string;
begin
  Result := nil;
  
  dataSet := TdlDataSet.Create(Ares);
  try
    dataSet.SQL.Text := sql;
    dataSet.Debug := true;
    dataSet.DontHandleException := true;

    for i := 0 to Length(params) - 1 do
    begin 
        dataSet.Params.ParamByName('p' + inttostr(i)).Value := params[i];
    end;      
    dataSet.Open; 

    if dataSet.LastError <> null then
    begin
        raise Exception.Create(dataSet.LastError);
    end; 

    if not dataSet.EOF then
    begin
        blobFieldName := dataSet.Fields[0].FieldName; // Assuming the first field is the BLOB field

        if not dataSet.FieldByName(blobFieldName).IsNull then
        begin
          Result := TMemoryStream.Create;
          TMemoryStream(Result).LoadFromStream(dataSet.CreateBlobStream(dataSet.FieldByName(blobFieldName), bmRead));
        end;
    end;
    dataSet.Close;

  except on E:Exception do
    raise E;
  end;
end;




