joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ cat ~/.ssh/id_rsa.pub
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABgQCiZRQ7gq9qfWWPrwvRM9VbRIv7FafKpHibvkz4btdkY75aLrhT2HdqUZi0fF01MMcYE0/1BR8pQ7f9S40htc3/1unITbVWZ2B2meWXQ59QAqT/+r3/3u2ha5iJajXx0DFMworOq7C+mbU4rIpSRwmiBXAPj9PB44ax76oNMFBp5IUircA/YgpMsEYyH+eoBdSJt2/+ZVuagsCGCRltgX/akDN2b6p1MosVQ8Vdz3sLqxDEMveJVSuaLyyfmR4kaLASyXMLsGumrPunJTkBdd4Uh+Iw45rYpvHCm/r2tsK+gKY50qC1zf3kiiXoSrxPjAaL6Ed6iFBiqHIYatdmPHjru7HzvTOKPlNmdtrVd5djk9nmmwqNgYnq7+MwzmAlT33q1CVVs6mKzejWhF1UJJ7kholobdhx6nQMNkj252IM+y4XTFDjFQyV/6MZX/F0ujNg0OBYDCBP8mVj2dC0cYvTM9JJRHp9uuIu0cUX0alhVp8HWoB2HJamigIYEDjibsc= joy@Joy-TUF-PC
joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git push origin main
error: src refspec main does not match any
error: failed to push some refs to 'github.com:CSE330-FALL-2023/Assignment-3-1229960136.git'
joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git branch -M main
joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git push origin main
To github.com:CSE330-FALL-2023/Assignment-3-1229960136.git
! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'github.com:CSE330-FALL-2023/Assignment-3-1229960136.git'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushinghint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git pull --rebase
remote: Enumerating objects: 3, done.
remote: Counting objects: 100% (3/3), done.
remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
Unpacking objects: 100% (3/3), 598 bytes | 0 bytes/s, done.
From github.com:CSE330-FALL-2023/Assignment-3-1229960136
* [new branch]      main       -> origin/main
  There is no tracking information for the current branch.
  Please specify which branch you want to rebase against.
  See git-pull(1) for details.

  git pull <remote> <branch>

If you wish to set tracking information for this branch you can do so with:

    git branch --set-upstream-to=origin/<branch> main

joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git log
commit 2e7a24c6eca595f678ed8c3a3ed4fe2bd1d4344c (HEAD -> main)
Author: krazyjoy <huang.joy.0506@gmail.com>
Date:   Sat Sep 23 17:00:09 2023 -0700

    pull
joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git push origin main
To github.com:CSE330-FALL-2023/Assignment-3-1229960136.git
! [rejected]        main -> main (non-fast-forward)
error: failed to push some refs to 'github.com:CSE330-FALL-2023/Assignment-3-1229960136.git'
hint: Updates were rejected because the tip of your current branch is behindhint: its remote counterpart. Integrate the remote changes (e.g.
hint: 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git pull remote ^C
joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git pull git@github.com:CSE330-FALL-2023/Assignment-3-1229960136.git main
From github.com:CSE330-FALL-2023/Assignment-3-1229960136
* branch            main       -> FETCH_HEAD
  hint: You have divergent branches and need to specify how to reconcile them.hint: You can do so by running one of the following commands sometime beforehint: your next pull:
  hint:
  hint:   git config pull.rebase false  # merge (the default strategy)
  hint:   git config pull.rebase true   # rebase
  hint:   git config pull.ff only       # fast-forward only
  hint:
  hint: You can replace "git config" with "git config --global" to set a default
  hint: preference for all repositories. You can also pass --rebase, --no-rebase,
  hint: or --ff-only on the command line to override the configured default per
  hint: invocation.
  fatal: Need to specify how to reconcile divergent branches.
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git config pull.rebase false
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git pull git@github.com:CSE330-FALL-2023/Assignment-3-1229960136.git main
  From github.com:CSE330-FALL-2023/Assignment-3-1229960136
* branch            main       -> FETCH_HEAD
  fatal: refusing to merge unrelated histories
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$  git branch --set-upstream-to=origin/main main
  Branch 'main' set up to track remote branch 'main' from 'origin'.
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ ls
  README.md
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git pull git@github.com:CSE330-FALL-2023/Assignment-3-1229960136.git main
  From github.com:CSE330-FALL-2023/Assignment-3-1229960136
* branch            main       -> FETCH_HEAD
  fatal: refusing to merge unrelated histories
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git pull origin master --allow-unrelated-histories
  git merge origin origin/master
  fatal: couldn't find remote ref master
  merge: origin - not something we can merge
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git merge origin origin/master
  merge: origin - not something we can merge
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git merge origin origin/main
  merge: origin - not something we can merge
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git pull origin main --allow-unrelated-histories
  From github.com:CSE330-FALL-2023/Assignment-3-1229960136
* branch            main       -> FETCH_HEAD
  Merge made by the 'ort' strategy.
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git merge origin origin/main
  merge: origin - not something we can merge
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git fetch origin main
  From github.com:CSE330-FALL-2023/Assignment-3-1229960136
* branch            main       -> FETCH_HEAD
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git checkout main
  Already on 'main'
  Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$ git push -u origin main
  Enumerating objects: 9, done.
  Counting objects: 100% (9/9), done.
  Delta compression using up to 20 threads
  Compressing objects: 100% (8/8), done.
  Writing objects: 100% (8/8), 1.23 KiB | 17.00 KiB/s, done.
  Total 8 (delta 1), reused 0 (delta 0), pack-reused 0
  remote: Resolving deltas: 100% (1/1), done.
  To github.com:CSE330-FALL-2023/Assignment-3-1229960136.git
  a37a28f..5009eba  main -> main
  Branch 'main' set up to track remote branch 'main' from 'origin'.
  joy@Joy-TUF-PC:/mnt/d/ASU/OS/HW3/Assignment-3-1229960136-main$