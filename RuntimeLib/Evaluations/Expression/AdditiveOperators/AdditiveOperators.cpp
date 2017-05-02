#include <RuntimeLib/Evaluations/Expression/AdditiveOperators/AdditiveOperators.h>

LanguageType *AdditionOperator(LanguageType *lref, LanguageType *rref) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto rval = _ToLanguageType(GetValue(rref));
	auto lprim = ToPrimitive(lval);
	auto rprim = ToPrimitive(rval);
	if (dynamic_cast<StringType *>(lprim) || dynamic_cast<StringType *>(rprim)) {
		auto lstr = ToString(lprim)->_getValue();
		auto rstr = ToString(rprim)->_getValue();
		auto result = new StringType(lstr + rstr);
		return dynamic_cast<LanguageType *>(result);
	}
	auto lnum = ToNumber(lprim)->_getValue();
	auto rnum = ToNumber(rprim)->_getValue();
	auto result = new NumberType(lnum + rnum);
	return dynamic_cast<LanguageType *>(result);
}

LanguageType *SubtractionOperator(LanguageType *lref, LanguageType *rref) {
	auto lval = _ToLanguageType(GetValue(lref));
	auto rval = _ToLanguageType(GetValue(rref));
	auto lnum = ToNumber(lval)->_getValue();
	auto rnum = ToNumber(rval)->_getValue();
	auto result = new NumberType(lnum - rnum);
	return dynamic_cast<LanguageType *>(result);
}