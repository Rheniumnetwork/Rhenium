// Copyright (c) 2011-2013 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

<<<<<<< HEAD
#ifndef BITCOIN_QT_ASKPASSXRHASEDIALOG_H
#define BITCOIN_QT_ASKPASSXRHASEDIALOG_H
=======
#ifndef BITCOIN_QT_ASKPASSPHRASEDIALOG_H
#define BITCOIN_QT_ASKPASSPHRASEDIALOG_H
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e

#include <QDialog>

class WalletModel;

namespace Ui
{
class AskPassphraseDialog;
}

/** Multifunctional dialog to ask for passphrases. Used for encryption, unlocking, and changing the passphrase.
 */
class AskPassphraseDialog : public QDialog
{
    Q_OBJECT

public:
    enum Mode {
        Encrypt,         /**< Ask passphrase twice and encrypt */
        UnlockAnonymize, /**< Ask passphrase and unlock only for anonymization */
        Unlock,          /**< Ask passphrase and unlock */
        ChangePass,      /**< Ask old passphrase + new passphrase twice */
        Decrypt          /**< Ask passphrase and decrypt wallet */
    };

    explicit AskPassphraseDialog(Mode mode, QWidget* parent, WalletModel* model);
    ~AskPassphraseDialog();

    void accept();

private:
    Ui::AskPassphraseDialog* ui;
    Mode mode;
    WalletModel* model;
    bool fCapsLock;

private slots:
    void textChanged();

protected:
    bool event(QEvent* event);
    bool eventFilter(QObject* object, QEvent* event);
};

<<<<<<< HEAD
#endif // BITCOIN_QT_ASKPASSXRHASEDIALOG_H
=======
#endif // BITCOIN_QT_ASKPASSPHRASEDIALOG_H
>>>>>>> 3cb3aa92098e45afdbb5a3121b74b2ebf7e1705e
