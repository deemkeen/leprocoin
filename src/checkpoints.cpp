// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of // TODO: needs to adjusted for checkpoint checks, also see main.cpp
        ( 0, uint256("0xe7151d967c20da83b5dab06cec55c490569df3197465e843860210e340d837ea"))
        ( 40000, uint256("0x860f803c0db63d3af41f47a27f555c4a22d501e6e99b550849b12d0a1be621db"))
	( 70000, uint256("0xea78a76ca65f1e2048f7be1edd10bf53d79457f68ba7c74cb43f71b0cda4e692"))
	( 100000, uint256("0x6ba8bd55f22cc399f8a13b5ceea7247308f932884b2190705c93748f9326d261"))
	( 140000, uint256("0xa4bc4ed45083dbfa3ddb269019872c7201484b268ca159d73066b6965a0e172f"))
	( 169997, uint256("0xbcb0f8608fe8ccc23a5b529083e4fee094d9dcfab113e5d9de23c7470b29294e"))
        ;

    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
