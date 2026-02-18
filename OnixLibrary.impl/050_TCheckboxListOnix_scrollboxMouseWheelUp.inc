procedure TCheckboxListOnix.scrollboxMouseWheelUp(Sender: TObject; Shift: TShiftState; MousePos: TPoint; var Handled: Boolean);  
begin  
  TcxScrollBox(Sender).VertScrollBar.Position := TcxScrollBox(Sender).VertScrollBar.Position - 1;  
end;




