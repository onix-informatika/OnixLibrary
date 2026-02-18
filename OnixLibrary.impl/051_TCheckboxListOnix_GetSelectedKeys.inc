function TCheckboxListOnix.GetSelectedKeys():TStringList;
var selectedKeys: TStringList;
  i: Integer;    
  Child: TControl;
begin
    selectedKeys := TStringList.Create();
    for i := 0 to scrollbox.ControlCount - 1 do
    begin
        Child := scrollbox.Controls[i];
        
        if Child is TcxCheckbox then
        begin
            with Child as TcxCheckBox do
            begin
                 if Checked then
                 begin
                    selectedKeys.Add(values[Tag - 1]);
                 end;
            end;
        end;
    end;
    result := selectedKeys;
end;




