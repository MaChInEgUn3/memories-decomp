PYTHON ?= python3
ROOT := $(CURDIR)

export HOME := $(ROOT)/tmp/home
export TMPDIR := $(ROOT)/tmp
export XDG_CACHE_HOME := $(ROOT)/tmp/cache
export PIP_CACHE_DIR := $(ROOT)/tmp/pip-cache
export PYTHONPYCACHEPREFIX := $(ROOT)/tmp/pycache
export NPM_CONFIG_CACHE := $(ROOT)/tmp/npm-cache
export CARGO_HOME := $(ROOT)/tools/environments/cargo
export RUSTUP_HOME := $(ROOT)/tools/environments/rustup
export GOPATH := $(ROOT)/tools/environments/go
export GOMODCACHE := $(ROOT)/tools/environments/go/pkg/mod

.DEFAULT_GOAL := help

.PHONY: help workspace verify-inputs

help:
	@printf '%s\n' \
		'Available targets:' \
		'  verify-inputs  Validate the SLUS-01411 executable and DATA files' \
		'  workspace      Validate that commands are running from the project root'

workspace:
	@$(PYTHON) tools/project/workspace.py

verify-inputs: workspace
	@$(PYTHON) tools/project/verify_inputs.py
