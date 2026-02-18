constructor TCheckboxListOnix.Create(AParent: TComponent); override;
begin    
    totalScrollboxHeight := 0;
    parent := AParent;
    values := TStringList.Create();
    popupMenu := TPopupMenu.Create(AParent);
    addMenuItems();
    scrollbox := TcxScrollBox.Create(AParent);
    with scrollbox do
    begin  
        Align := alClient;
        Parent := AParent;
        OnContextPopup := popupMenuPopup;
        OnMouseWheelDown := scrollboxMouseWheelDown;
        OnMouseWheelUp := scrollboxMouseWheelUp;
    end;
end;




