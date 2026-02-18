function oxAddCheckboxColumn(gridName: String; columnCaption: String; columnFieldName: String; width: integer = 50): TcxGridDBColumn;
begin
	Result := oxAddColumn(gridName, columnCaption, columnFieldName, width);
    with Result do
    begin
        PropertiesClass := TcxCheckBoxProperties;
        with TcxCheckBoxProperties(Properties) do
        begin
            ValueChecked := 'T';
            ValueUnchecked := 'F';
        end;
    end;
end;




