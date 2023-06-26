# DESCRIPTION OF METHODOLOGY FOR THIS PROJECT

## TEMPLATE WORKFLOW

Product Manager:	**Onwuta Ebube Gideon**

Dev site:	**https://github.com/Ebuube/monty**

Branch deployed on dev site:	**develop**

Live site:	**----------------------------**

Branch deployed on live site:	**------------------------**

When starting a dev ticket, branch from:	**develop**

Use this style to create a branch off develop for a ticket:	**git checkout --track -b \<new\_branch\_name\> \<origin\_develop\>**

When starting a hotfix ticket, branch from:	**main**

Format of hotfix branch name:	**hotfix-\<ticket id\>-description**

When updating your work with the remote, use:	**git pull --rebase=preserve origin \<local branch name\>**

When merging your work post review, use:	**git push --set-upstream origin \<local branch name\>**

## NAMING CONVENTION

When dealing with an issue/ticket, create a branch from the remote `develop` branch. Give the branch this name: **\<name of developer\>/\<ticket\_or\_issue\_id-ticket\_description\>**

Example: `Ebuube/12-documentation`

## COMMITTING
When committing your final work just prior to review, use this as the log summary:

```
[#\<ticket\_id\>]  \<ticket description \>

Detailed info of operations done.
```

Example:
```
$ git commit --amend

#14 Initial documentation

Updated style of workflow in WORKFLOW.md
Updated README.md to explain what the repository is all about
```

## MAKING CHANGES

**Don't** use `git reset` to make changes in the `develop` branch.
Altering the history of your repository is a big no-no if you’ve already published the commits

## TICKET PROGRESSION

* **To do**: Any project that has not been deemed relevant for this work effort (or sprint. This is also referred as `product backlog`. It should be prioritized to give hints to the team on what should be worked on in the next work sprint

* **READY FOR WORK**: Prioritized tickets for this work iteration. They might be the blockers for tickets in the backlog, or simply the next piece the team has chosen to work on.
	> **Note**: This can be sub-categorized as `Ready for Development`, `Ready for Code Review`, `Ready for Testing`, `Ready for Client Approval`, and `Ready for Deployment`.

* **IN PROGRESS**: A developer is currently working on this ticket, or a quality assurance review is being done.
	> **Note**: This can be sub-divided into `In Development`, and `In Testing`.

* **COMPLETED**: The work has been finished, or has been canceled. Perhaps, there were follow-up tickets, but only very rarely should a ticket be reopened after it has passed a code review, quality assurance review, and a client review.


## BASIC WORKFLOW

1. As you begin a ticket, update the status in the ticket tracker (GitHub project feature concerning the repository) to say the ticket is `In Progress`. This will notify your team about what you are currently working on, and will give you the number for the branch you will create to work on your ticket.

2. From the branch develop, create a new branch whose name includes the `ticket ID` and a terse (very concise) description of the work. If you are working on tickets that have sub-tasks, ensure the branch name uses the most relevant ticket number. For bigger feature, this ticket might be referred to in your ticketing system as a `Meta ticket` or `Epic ticket`. If you are working on only part of the larger feature, you should use the smallest relevant ticket number. Your ticket system might refer to this as a `user story`, an `issue`, or `bug ticket`.

3. Work on your ticket, ensuring you keep the ticket branch up to date with any changes that might have been incorporated into the branch `master` since you started your work. Begin each commit message with the ticket number enclosed in square brackets: `[#1234]`.

4. Run relevant tests for your code to ensure typos and basic errors are caught. This may include a spellcheck, and a language syntax check ([linting](https://en.wikipedia.org/wiki/Lint_(software))). If you are working in a test driven environment you will definitely have additional tests to run.

5. When you have completed your work (or think you have!), make a final commit with the keyword `Resolves` and then the ticket number: `Resolves #1234`.

6. Optionally, push your ticket branch to the code hosting repository. With the keyword in place in your commit message, this will move your ticket tracker forward to the next step.


## CONTRIBUTOR ACKNOWLEDGEMENT
If a participant contributes to this repository, he should add his name to the `AUTHORS.md` file
