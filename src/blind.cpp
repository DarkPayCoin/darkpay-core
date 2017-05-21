// Copyright (c) 2017 The Particl developers
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

#include "blind.h"

#include <assert.h>
#include <secp256k1.h>
#include <secp256k1_rangeproof.h>

#include "util.h"


secp256k1_context *secp256k1_ctx_blind = NULL;

int SelectRangeProofParameters(uint64_t nValueIn, uint64_t &minValue, int &exponent, int &nBits)
{
    
    
    
    return 0;
};

int GetRangeProofInfo(const std::vector<uint8_t> &vRangeproof, int &rexp, int &rmantissa, CAmount &min_value, CAmount &max_value)
{
    
    return (!(secp256k1_rangeproof_info(secp256k1_ctx_blind,
        &rexp, &rmantissa, (uint64_t*) &min_value, (uint64_t*) &max_value,
        &vRangeproof[0], vRangeproof.size()) == 1));
};

void ECC_Start_Blinding()
{
    assert(secp256k1_ctx_blind == NULL);

    secp256k1_context *ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY);
    assert(ctx != NULL);

    secp256k1_ctx_blind = ctx;
};

void ECC_Stop_Blinding()
{
    secp256k1_context *ctx = secp256k1_ctx_blind;
    secp256k1_ctx_blind = NULL;

    if (ctx)
    {
        secp256k1_context_destroy(ctx);
    };
};
