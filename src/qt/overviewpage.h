// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_OVERVIEWPAGE_H
#define BITCOIN_QT_OVERVIEWPAGE_H

#include "amount.h"

#include <QWidget>

class ClientModel;
class TransactionFilterProxy;
class TxViewDelegate;
class WalletModel;

namespace Ui
{
class OverviewPage;
}

QT_BEGIN_NAMESPACE
class QModelIndex;
QT_END_NAMESPACE

/** Overview ("home") page widget */
class OverviewPage : public QWidget
{
    Q_OBJECT

public:
    explicit OverviewPage(QWidget* parent = 0);
    ~OverviewPage();

    void setClientModel(ClientModel* clientModel);
    void setWalletModel(WalletModel* walletModel);
    void showOutOfSyncWarning(bool fShow);
<<<<<<< HEAD

public slots:
    void setBalance(const CAmount& balance, const CAmount& unconfirmedBalance, const CAmount& immatureBalance, 
                    const CAmount& zerocoinBalance, const CAmount& unconfirmedZerocoinBalance, const CAmount& immatureZerocoinBalance,
                    const CAmount& watchOnlyBalance, const CAmount& watchUnconfBalance, const CAmount& watchImmatureBalance);
=======
    void updateCoinMixingProgress();

public slots:
    void obfuScationStatus();
    void setBalance(const CAmount& balance, const CAmount& unconfirmedBalance, const CAmount& immatureBalance, const CAmount& anonymizedBalance, const CAmount& watchOnlyBalance, const CAmount& watchUnconfBalance, const CAmount& watchImmatureBalance);
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e

signals:
    void transactionClicked(const QModelIndex& index);

private:
    QTimer* timer;
    Ui::OverviewPage* ui;
    ClientModel* clientModel;
    WalletModel* walletModel;
    CAmount currentBalance;
    CAmount currentUnconfirmedBalance;
    CAmount currentImmatureBalance;
<<<<<<< HEAD
    CAmount currentZerocoinBalance;
    CAmount currentUnconfirmedZerocoinBalance;
    CAmount currentimmatureZerocoinBalance;
=======
    CAmount currentAnonymizedBalance;
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
    CAmount currentWatchOnlyBalance;
    CAmount currentWatchUnconfBalance;
    CAmount currentWatchImmatureBalance;
    int nDisplayUnit;
<<<<<<< HEAD
    void getPercentage(CAmount nTotalBalance, CAmount nZerocoinBalance, QString& sXRHPercentage, QString& szXRHPercentage);
=======
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e

    TxViewDelegate* txdelegate;
    TransactionFilterProxy* filter;

private slots:
<<<<<<< HEAD
=======
    void toggleCoinMixing();
    void coinmixingAuto();
    void coinmixingReset();
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
    void updateDisplayUnit();
    void handleTransactionClicked(const QModelIndex& index);
    void updateAlerts(const QString& warnings);
    void updateWatchOnlyLabels(bool showWatchOnly);
};

#endif // BITCOIN_QT_OVERVIEWPAGE_H
