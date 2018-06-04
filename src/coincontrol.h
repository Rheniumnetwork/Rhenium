// Copyright (c) 2011-2013 The Bitcoin developers
<<<<<<< HEAD
// Copyright (c) 2014-2016 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
=======
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_COINCONTROL_H
#define BITCOIN_COINCONTROL_H

#include "primitives/transaction.h"
#include "script/standard.h"

/** Coin Control Features. */
class CCoinControl
{
public:
    CTxDestination destChange;
    bool useObfuScation;
    bool useRhenFAST;
    bool fSplitBlock;
    int nSplitBlock;
    //! If false, allows unselected inputs, but requires all selected inputs be used
    bool fAllowOtherInputs;
    //! Includes watch only addresses which match the ISMINE_WATCH_SOLVABLE criteria
    bool fAllowWatchOnly;
    //! Minimum absolute fee (not per kilobyte)
    CAmount nMinimumTotalFee;

    CCoinControl()
    {
        SetNull();
    }

    void SetNull()
    {
        destChange = CNoDestination();
        setSelected.clear();
        useRhenFAST = false;
<<<<<<< HEAD
        useObfuScation = false;
        fAllowOtherInputs = false;
        fAllowWatchOnly = true;
=======
        useObfuScation = true;
        fAllowOtherInputs = false;
        fAllowWatchOnly = false;
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
        nMinimumTotalFee = 0;
        fSplitBlock = false;
        nSplitBlock = 1;
    }

    bool HasSelected() const
    {
        return (setSelected.size() > 0);
    }

    bool IsSelected(const uint256& hash, unsigned int n) const
    {
        COutPoint outpt(hash, n);
        return (setSelected.count(outpt) > 0);
    }

    void Select(const COutPoint& output)
    {
        setSelected.insert(output);
    }

    void UnSelect(const COutPoint& output)
    {
        setSelected.erase(output);
    }

    void UnSelectAll()
    {
        setSelected.clear();
    }

    void ListSelected(std::vector<COutPoint>& vOutpoints)
    {
        vOutpoints.assign(setSelected.begin(), setSelected.end());
    }

<<<<<<< HEAD
    unsigned int QuantitySelected()
    {
        return setSelected.size();
    }

    void SetSelection(std::set<COutPoint> setSelected)
    {
        this->setSelected.clear();
        this->setSelected = setSelected;
    }

=======
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
private:
    std::set<COutPoint> setSelected;
};

#endif // BITCOIN_COINCONTROL_H
