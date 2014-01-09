LeproCoin (LPC) - a shameless clone of SmallChange, which uses scrypt
as a proof of work scheme and is intended for microtransactions.
 - 15 seconds block targets: beat that MinCoin! ;)
 - 42 007 680 total coins
 - no subsidy after approximately 5 years;
 - 4 coins per generated block
 - difficulty retargets every 0.35 days
 - currently peers are looked up over IRC only

Other than that, this coin is exactly like Litecoin and could be used
as a real cryptocurrency. All of the coin parameters are chosen arbitrarily
or at most with 'fairness' towards everyone in mind.

Credits go to the original authors/communities that
created Bitcoin, Litecoin and SmallChange.

Binary Qt-Clients
===================

Windows-Build:  http://leprocoin.org/leprocoin-qt-win.zip

OSX-Build:  http://leprocoin.org/leprocoin-qt-mac-new.zip


leprocoin.conf
===================

    rpcuser=your-user
    rpcpassword=your-pass
    rpcport=9031
    addnode=91.250.113.69
    addnode=195.39.206.15
    addnode=93.186.202.8
    addnode=77.180.79.191
    server=1
    daemon=1


Development process
===================

Developers work in their own trees, then submit pull requests when
they think their feature or bug fix is ready.

The patch will be accepted if there is broad consensus that it is a
good thing.  Developers should expect to rework and resubmit patches
if they don't match the project's coding conventions (see coding.txt)
or are controversial.

The master branch is regularly built and tested, but is not guaranteed
to be completely stable. Tags are regularly created to indicate new
official, stable release versions of Litecoin.

Feature branches are created when there are major new features being
worked on by several people.

From time to time a pull request will become outdated. If this occurs, and
the pull is no longer automatically mergeable; a comment on the pull will
be used to issue a warning of closure. The pull will be closed 15 days
after the warning if action is not taken by the author. Pull requests closed
in this manner will have their corresponding issue labeled 'stagnant'.

Issues with no commits will be given a similar warning, and closed after
15 days from their last activity. Issues closed in this manner will be 
labeled 'stale'.
