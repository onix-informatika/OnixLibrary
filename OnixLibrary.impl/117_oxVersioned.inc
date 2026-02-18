procedure oxVersioned(stepId: integer; objectName: String; objectType: String; version: integer);
begin
    TransactionStart();
    try
        Versioned(stepId, objectName, version, objectType, objectName); // naziv procedure koju overrideamo, pa verzija naĹˇe override procedure, primjer se nalazi u SQL-u 3, tu treba napraviti override s istim parametrima
        TransactionCommit();
     except on E:Exception do
        begin
           TransactionRollback(); 
        end
     end;
end;




