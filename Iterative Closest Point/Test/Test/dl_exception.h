#ifndef DL_EXCEPTION_H
#define DL_EXCEPTION_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/**
 * Used for exception handling.
 */
class DL_Exception {}
;

/**
 * Used for exception handling.
 */
class DL_NullStrExc : public DL_Exception {}
;

/**
 * Used for exception handling.
 */
class DL_GroupCodeExc : public DL_Exception {
    DL_GroupCodeExc(int gc=0) : groupCode(gc) {}
    int groupCode;
};
#endif

