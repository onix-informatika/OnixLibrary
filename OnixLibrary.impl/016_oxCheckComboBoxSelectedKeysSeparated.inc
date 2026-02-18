function oxCheckComboBoxSelectedKeysSeparated(cbx: TcxCheckComboBox; delimiter: String = ','): String;
var ts: TStringList;
begin
    ts := oxCheckComboBoxSelectedKeys(cbx);
    ts.Delimiter := delimiter;
    Result := ts.CommaText;
end;




