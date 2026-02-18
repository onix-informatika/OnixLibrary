function oxSQLStepResultWithParamsAnotherAres(stepId: Integer; aresAcKey: String; params: array of Variant): String;
var stepSQL: String;
begin
    stepSQL := oxGetStepSQLFromAres(stepId, aresAcKey);
    result := oxSQLExpWithParams(stepSQL, params);
end;




