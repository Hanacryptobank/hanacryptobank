// Copyright (c) 2020 The HanaCryptoBank developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
 
#include <amount.h>
#include <util.h>

/**
 * The number of blocks that both new and old MN collateral value will
 * be accepted, for smoother transition.
 */
const unsigned int COLLATERAL_TRANSITION_BLOCKS = 100;

/**
 * Determine the masternode collateral value based on block height
 */
CAmount CollateralRequired(int nHeight)
{
    CAmount nCollateralRequired;
    
    if (nHeight <= 500) {
        nCollateralRequired = 0 * COIN;
    } else if (nHeight <= 10000) {
        nCollateralRequired = 50 * COIN;
    } else if (nHeight <= 20000) {
        nCollateralRequired = 100 * COIN;
    } else if (nHeight <= 30000) {
        nCollateralRequired = 150 * COIN;
    } else if (nHeight <= 40000) {
        nCollateralRequired = 225 * COIN;
    } else if (nHeight <= 50000) {
        nCollateralRequired = 300 * COIN;
    } else if (nHeight <= 60000) {
        nCollateralRequired = 400 * COIN;
    } else if (nHeight <= 70000) {
        nCollateralRequired = 500 * COIN;
    } else if (nHeight <= 80000) {
        nCollateralRequired = 600 * COIN;
    } else if (nHeight <= 100000) {
        nCollateralRequired = 700 * COIN;
    } else if (nHeight <= 125000) {
        nCollateralRequired = 800 * COIN;
    } else if (nHeight <= 150000) {
        nCollateralRequired = 900 * COIN;
    } else if (nHeight <= 200000) {
        nCollateralRequired = 1000 * COIN;
    } else if (nHeight <= 400000) {
        nCollateralRequired = 1150 * COIN;
	} else if (nHeight <= 500000) {
        nCollateralRequired = 1300 * COIN;
	} else if (nHeight <= 750000) {
        nCollateralRequired = 1500 * COIN;
	} else if (nHeight <= 1000000) {
        nCollateralRequired = 1750 * COIN;
	} else if (nHeight <= 1500000) {
        nCollateralRequired = 2000 * COIN;
	} else if (nHeight <= 2000000) {
        nCollateralRequired = 2500 * COIN;
    } else {
        nCollateralRequired = 2500 * COIN;
    }

    return nCollateralRequired;
}


/**
 * Provide transition period for masternode collateral change to avoid
 * unneccessary issues to masternode operators for the amount of 
 * COLLATERAL_TRANSITION_BLOCKS blocks during the collateral change.
 */
bool IsValidCollateral(CAmount nAmountToCheck, int nHeight)
{
    return (
        nAmountToCheck == CollateralRequired(nHeight) || 
        nAmountToCheck == CollateralRequired(nHeight - floor(COLLATERAL_TRANSITION_BLOCKS / 2)) ||
        nAmountToCheck == CollateralRequired(nHeight + floor(COLLATERAL_TRANSITION_BLOCKS / 2))
        );
}