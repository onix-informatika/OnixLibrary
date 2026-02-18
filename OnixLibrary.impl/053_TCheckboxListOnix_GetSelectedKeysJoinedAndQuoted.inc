function TCheckboxListOnix.GetSelectedKeysJoinedAndQuoted(by: String = ','):string;
var selectedKeys: TStringList;
    key: string;
begin
    result := '';
    selectedKeys := GetSelectedKeys();
    for key in selectedKeys do
    begin
        result := result + QuotedStr(key);
        if not (selectedKeys.IndexOf(key) = selectedKeys.Count - 1) then
        begin
            result := result + by;
        end;
    end;
end;




