# Contributing

## Important
Anyone wanting to contribute *MUST* read the following and adhere to the steps
outlined, in order to not violate any copyright.

This decompile is a [clean room design](https://en.wikipedia.org/wiki/Clean_room_design).
It *MUST* not incorperate any code owned by Nintendo or other third parties.

In order to achieve this, all code has to be written completely fresh, without
reference to any third party code, no matter if leaked or not.

Derived from this there is the following requirement for contributors:

- Contributors *MUST NOT* study or refer to any code owned by Nintendo or other
  third parties.

## LLM Policy

This is a human-driven decompilation. It is a passion project that exists to understand and document Metroid Fusion. If you use an LLM (large language model), the following rules must be followed when submitting a PR:
- You must understand every part of what you submit. Reviewers may ask you to explain any part of your PR.
- Disclose that you used an LLM and say what it was used for.
- PRs should ideally be limited in scope to a specific goal (ex: adding new functions to a file, renaming enum values).

Here are some example uses of LLMs are allowed:
- Understanding the layout of the repo or asking where certain logic exists
- Brainstorming the purpose of a variable or function
- Explaining a decision the compiler made, such as why a particular register was used
- Anything that isn't shipped with the repo, such as personal tools/scripts or PR/issue messages

The following uses of LLMs are **not** permitted:
- Using LLMs to match functions or data
- Copy/pasting LLM output
- Letting an LLM write code comments or documentation

PC ports, enhancements, and engine modifications are outside of the scope for this repository.

## Submitting a Change
1. Clone this repository and follow the setup instructions if you haven't already
2. For any set of changes you want to submit, create a branch off of `main` (make sure you're on the latest commit)
3. When ready to submit your changes, make sure the ROM still compiles (`make`)
4. If the ROM compiles, make sure the ROM still matches the base ROM (`make check`)
- Recommended: run `./check_roms.sh` to build and check ROMs for every supported region (may require `chmod +x check_roms.sh`). You will need a base ROM for each supported region.
5. Open a PR on github, and add a description that summarizes your changes
