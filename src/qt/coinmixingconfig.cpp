#include "coinmixingconfig.h"
#include "ui_coinmixingconfig.h"

#include "bitcoinunits.h"
#include "guiconstants.h"
#include "init.h"
#include "optionsmodel.h"
#include "walletmodel.h"

#include <QKeyEvent>
#include <QMessageBox>
#include <QPushButton>
#include <QSettings>

CoinMixingConfig::CoinMixingConfig(QWidget* parent) : QDialog(parent),
                                                        ui(new Ui::CoinMixingConfig),
                                                        model(0)
{
    ui->setupUi(this);

    connect(ui->buttonBasic, SIGNAL(clicked()), this, SLOT(clickBasic()));
    connect(ui->buttonHigh, SIGNAL(clicked()), this, SLOT(clickHigh()));
    connect(ui->buttonMax, SIGNAL(clicked()), this, SLOT(clickMax()));
}

CoinMixingConfig::~CoinMixingConfig()
{
    delete ui;
}

void CoinMixingConfig::setModel(WalletModel* model)
{
    this->model = model;
}

void CoinMixingConfig::clickBasic()
{
    configure(true, 1000, 2);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("CoinMixing Configuration"),
        tr(
            "CoinMixing was successfully set to basic (%1 and 2 rounds). You can change this at any time by opening Rhenium's configuration screen.")
            .arg(strAmount));

    close();
}

void CoinMixingConfig::clickHigh()
{
    configure(true, 1000, 8);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("CoinMixing Configuration"),
        tr(
            "CoinMixing was successfully set to high (%1 and 8 rounds). You can change this at any time by opening Rhenium's configuration screen.")
            .arg(strAmount));

    close();
}

void CoinMixingConfig::clickMax()
{
    configure(true, 1000, 16);

    QString strAmount(BitcoinUnits::formatWithUnit(
        model->getOptionsModel()->getDisplayUnit(), 1000 * COIN));
    QMessageBox::information(this, tr("CoinMixing Configuration"),
        tr(
            "CoinMixing was successfully set to maximum (%1 and 16 rounds). You can change this at any time by opening Rhenium's configuration screen.")
            .arg(strAmount));

    close();
}

void CoinMixingConfig::configure(bool enabled, int coins, int rounds)
{
    QSettings settings;

    settings.setValue("nCoinMixingRounds", rounds);
    settings.setValue("nAnonymizeRheniumAmount", coins);

    nCoinMixingRounds = rounds;
    nAnonymizeRheniumAmount = coins;
}
