Function oxColumnByFieldName(TableView: TcxGridDBTableView; Const FieldName:
                             String): TcxGridDBColumn;

Var 
  i: Integer;
Begin
  Result := Nil;
  // Default result for "not found"

  For i := 0 To TableView.ColumnCount - 1 Do
    Begin
      If Assigned(TableView.Columns[i].DataBinding) And
         Assigned(TableView.Columns[i].DataBinding.Field) And
         SameText(TableView.Columns[i].DataBinding.Field.FieldName, FieldName)
        Then
        Begin
          Result := TableView.Columns[i];
          Break;
        End;
    End;
End;



