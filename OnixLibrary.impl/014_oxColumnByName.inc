Function oxColumnByName(TableView: TcxGridDBTableView; Const ColName: String):




                                                                 TcxGridDBColumn
;

Var 
  i: Integer;
Begin
  Result := Nil;
  // Default result for "not found"

  For i := 0 To TableView.ColumnCount - 1 Do
    Begin
      If SameText(TableView.Columns[i].Name, ColName) Then
        Begin
          Result := TableView.Columns[i];
          Break;
        End;
    End;
End;





