procedure TCheckboxListOnix.addMenuItems();
var currentMenuItem: TMenuItem;
begin
    currentMenuItem := TMenuItem.Create(popupMenu);
    currentMenuItem.Caption := 'Izaberi sve';
    currentMenuItem.OnClick := checkAllMenuItemClicked;
    popupMenu.Items.Add(currentMenuItem);
    
    currentMenuItem := TMenuItem.Create(popupMenu);
    currentMenuItem.Caption := 'Odaberi sve';
    currentMenuItem.OnClick := uncheckAllMenuItemClicked;
    popupMenu.Items.Add(currentMenuItem);
    
    currentMenuItem := TMenuItem.Create(popupMenu);
    currentMenuItem.Caption := 'Izaberi inverzno';
    currentMenuItem.OnClick := checkInverseMenuItemClicked;
    popupMenu.Items.Add(currentMenuItem);
end;




