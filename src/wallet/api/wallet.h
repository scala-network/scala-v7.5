// Copyright (c) 2014-2016, The Monero Project
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#ifndef WALLET_IMPL_H
#define WALLET_IMPL_H

#include "wallet/wallet2_api.h"
#include "wallet/wallet2.h"

#include <string>


namespace Bitmonero {


class WalletImpl : public Wallet
{
public:
    WalletImpl(bool testnet = false);
    ~WalletImpl();
    bool create(const std::string &path, const std::string &password,
                const std::string &language);
    bool open(const std::string &path, const std::string &password);
    bool recover(const std::string &path, const std::string &seed);
    bool close();
    std::string seed() const;
    std::string getSeedLanguage() const;
    void setSeedLanguage(const std::string &arg);
    // void setListener(Listener *) {}
    int status() const;
    std::string errorString() const;
    bool setPassword(const std::string &password);
    std::string address() const;
    bool store(const std::string &path);
    bool init(const std::string &daemon_address, uint64_t upper_transaction_size_limit);
    bool connectToDaemon();
    uint64_t balance() const;
    uint64_t unlockedBalance() const;
    bool refresh();
    PendingTransaction * createTransaction(const std::string &dst_addr, uint64_t amount);
    virtual void disposeTransaction(PendingTransaction * t);
    virtual TransactionHistory * history() const;

private:
    void clearStatus();

private:
    friend class TransactionImpl;
    tools::wallet2 * m_wallet;
    int  m_status;
    std::string m_errorString;
    std::string m_password;
};


} // namespace

#endif

