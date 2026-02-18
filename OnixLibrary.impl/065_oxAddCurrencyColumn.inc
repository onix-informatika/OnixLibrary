function oxAddCurrencyColumn(gridName: String; columnCaption: String; columnFieldName: String; width: integer = 50): TcxGridDBColumn;
begin
	Result := oxAddColumn(gridName, columnCaption, columnFieldName, width);
    with Result do
    begin
        PropertiesClass := TcxCurrencyEditProperties;
        with TcxCurrencyEditProperties(Properties) do
        begin
        end;
    end;
end;




