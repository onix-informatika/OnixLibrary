function oxSQLStepWithAresVariablesApplied(stepId: Integer): String;
var stepSQL: String;
begin
    stepSQL := oxGetStepSQLFromAres(stepId, ares.AcKey);
    stepSQL := oxApplyAresVariablesToString(stepSQL);
    result := stepSQL;
end;




