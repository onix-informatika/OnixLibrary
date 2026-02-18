procedure TCheckboxListOnix.checkInverseMenuItemClicked();
var
  i: Integer;    
  Child: TControl;
begin
    skipCheckboxCallbacks := true;
    try    
        for i := 0 to scrollbox.ControlCount - 1 do
        begin
            Child := scrollbox.Controls[i];
        
            if Child is TcxCheckbox then
            begin
                with Child as TcxCheckBox do
                begin
                    Checked := not Checked;
                end;
            end;
        end;  
    finally
        begin
            skipCheckboxCallbacks := false;
        end
    end;          
    if assigned(OnChanged) then OnChanged(self);
end;




