ROOT := $(CURDIR)
LOCAL_PYTHON := $(ROOT)/tools/environments/python/bin/python
PYTHON ?= $(if $(wildcard $(LOCAL_PYTHON)),$(LOCAL_PYTHON),python3)
BOOTSTRAP_PYTHON ?= python3

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

.PHONY: help workspace verify-inputs tools python-tools toolchain check-tools

help:
	@printf '%s\n' \
		'Available targets:' \
		'  tools          Install pinned project tools beneath tools/' \
		'  check-tools    Verify pinned local project tools' \
		'  verify-inputs  Validate the SLUS-01411 executable and DATA files' \
		'  workspace      Validate that commands are running from the project root'

workspace:
	@$(PYTHON) tools/project/workspace.py

verify-inputs: workspace
	@$(PYTHON) tools/project/verify_inputs.py

tools: python-tools toolchain

python-tools: verify-inputs
	@$(BOOTSTRAP_PYTHON) tools/bootstrap/bootstrap.py

toolchain: verify-inputs
	@$(BOOTSTRAP_PYTHON) tools/bootstrap/binutils.py

check-tools: workspace
	@$(PYTHON) tools/bootstrap/bootstrap.py --check
	@$(PYTHON) tools/bootstrap/binutils.py --check
