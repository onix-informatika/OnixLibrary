function oxCommaTextToTStringList(commaText: String; delimiter: String = ','): TStringList;
var sl: TStringList;
begin
    sl := TStringList.Create;
    sl.Delimiter := delimiter;
    sl.DelimitedText := commaText;
    result := sl;
end;




