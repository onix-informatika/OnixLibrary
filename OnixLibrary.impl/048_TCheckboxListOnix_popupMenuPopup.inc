procedure TCheckboxListOnix.popupMenuPopup(Sender: TObject; MousePos: TPoint; var Handled: Boolean);
var pt: TPoint;
begin
    pt := TcxScrollBox(Sender).ClientToScreen(MousePos);
    popupMenu.Popup(pt.X, pt.Y);
end;




