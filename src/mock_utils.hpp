//
// Copyright (C) 2018 Codership Oy <info@codership.com>
//

#include <wsrep_api.h> // Wsrep typedefs

// Forward declarations
namespace trrep
{
    class client_context;
    class mock_server_context;
}

#include "transaction_context.hpp"

//
// Utility functions
//
namespace trrep_mock
{

    // Simple BF abort method to BF abort unordered transasctions
    void bf_abort_unordered(trrep::client_context& cc,
                            trrep::transaction_context& tc);

    // BF abort method to abort transactions via provider
    void bf_abort_provider(trrep::mock_server_context& sc,
                           const trrep::transaction_context& tc,
                           wsrep_seqno_t bf_seqno);

    trrep::transaction_context applying_transaction(
        trrep::client_context& cc,
        const trrep::transaction_id& id,
        wsrep_seqno_t seqno,
        uint32_t flags);
}
