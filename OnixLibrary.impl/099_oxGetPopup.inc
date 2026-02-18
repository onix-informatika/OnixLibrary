function oxGetPopup(popup: String): TPopupMenu;
begin
    Result := TPopupMenu(AresFindComponent(popup, OwnerForm)); 
end;

// sve za onClickOverride




