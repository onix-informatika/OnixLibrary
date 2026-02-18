procedure TCheckboxListOnix.Add(AKey: string; AValue: string; AChecked: boolean = false);
var cb: TdlcxCheckBox;
begin
    if values.IndexOf(AKey) <> -1 then
    begin
        _macro.EventLogAdd('TCheckboxListOnix: dupli unos! : ' + AKey);
        exit; 
    end;

    cb := TdlcxCheckBox.Create(scrollbox); // ako nije u varijabli, onda se eventi ne okidaju
    with cb do
    begin                  
        Parent := scrollbox;
        Caption := AValue;
        values.Add(AKey);
        Tag := values.Count; 
        Top := totalScrollboxHeight;
        totalScrollboxHeight := totalScrollboxHeight + Height;
        Checked := AChecked;
        OnClick := self.OnChangedWrapper;
        with TcxCheckBoxProperties(Properties) do
        begin
            OnChanged := self.OnChangedWrapper; 
        end;
    end;
end;




