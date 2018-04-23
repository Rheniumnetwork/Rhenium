#ifndef COINMIXINGCONFIG_H
#define COINMIXINGCONFIG_H

#include <QDialog>

namespace Ui
{
class CoinMixingConfig;
}
class WalletModel;

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class CoinMixingConfig : public QDialog
{
    Q_OBJECT

public:
    CoinMixingConfig(QWidget* parent = 0);
    ~CoinMixingConfig();

    void setModel(WalletModel* model);


private:
    Ui::CoinMixingConfig* ui;
    WalletModel* model;
    void configure(bool enabled, int coins, int rounds);

private slots:

    void clickBasic();
    void clickHigh();
    void clickMax();
};

#endif // COINMIXINGCONFIG_H
