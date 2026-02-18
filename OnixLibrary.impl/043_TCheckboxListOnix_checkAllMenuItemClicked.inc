procedure TCheckboxListOnix.checkAllMenuItemClicked();
var
  i: Integer;    
  Child: TControl;
begin
    skipCheckboxCallbacks := true;
    for i := 0 to scrollbox.ControlCount - 1 do
    begin
        Child := scrollbox.Controls[i];
        
        if Child is TcxCheckbox then
        begin
            with Child as TcxCheckBox do
            begin
                Checked := true;
            end;
        end;
    end;       
    skipCheckboxCallbacks := false;
    if assigned(OnChanged) then OnChanged(self);
end;




