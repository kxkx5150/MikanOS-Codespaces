FROM mcr.microsoft.com/vscode/devcontainers/base:ubuntu-22.04

ARG USERNAME=vscode
ARG NOVNC_VERSION=1.2.0
ARG WEBSOCKIFY_VERSION=0.9.0

RUN apt-get update \
 && apt-get install -y --no-install-recommends \
    build-essential \
    llvm-14-dev \
    lld-14 \
    clang-14 \
    nasm \
    acpica-tools \
    uuid-dev \
    qemu-system-x86 \
    qemu-utils \
    qemu-system-gui \
    xauth \
    unzip \
    dosfstools \
    git \
    python-is-python3 \
    python3-distutils \
    python3-numpy \
    manpages-dev \
    curl \
    ca-certificates \
 && apt-get clean -y \
 && rm -rf /var/lib/apt/lists

RUN for item in \
        llvm-PerfectShuffle \
        llvm-ar \
        llvm-as \
        llvm-bcanalyzer \
        llvm-cat \
        llvm-cfi-verify \
        llvm-config \
        llvm-cov \
        llvm-c-test \
        llvm-cvtres \
        llvm-cxxdump \
        llvm-cxxfilt \
        llvm-diff \
        llvm-dis \
        llvm-dlltool \
        llvm-dwarfdump \
        llvm-dwp \
        llvm-exegesis \
        llvm-extract \
        llvm-lib \
        llvm-link \
        llvm-lto \
        llvm-lto2 \
        llvm-mc \
        llvm-mca \
        llvm-modextract \
        llvm-mt \
        llvm-nm \
        llvm-objcopy \
        llvm-objdump \
        llvm-opt-report \
        llvm-pdbutil \
        llvm-profdata \
        llvm-ranlib \
        llvm-rc \
        llvm-readelf \
        llvm-readobj \
        llvm-rtdyld \
        llvm-size \
        llvm-split \
        llvm-stress \
        llvm-strings \
        llvm-strip \
        llvm-symbolizer \
        llvm-tblgen \
        llvm-undname \
        llvm-xray \
        ld.lld \
        lld-link \
        clang \
        clang++ \
        clang-cpp \
    ; do \
        update-alternatives --install "/usr/bin/${item}" "${item}" "/usr/bin/${item}-14" 50 \
    ; done

# Install noVNC
RUN mkdir -p /usr/local/novnc \
 && curl -k -L -o /tmp/novnc.zip https://github.com/novnc/noVNC/archive/v${NOVNC_VERSION}.zip \
 && unzip /tmp/novnc.zip -d /usr/local/novnc/ \
 && cp /usr/local/novnc/noVNC-${NOVNC_VERSION}/vnc.html /usr/local/novnc/noVNC-${NOVNC_VERSION}/index.html \
 && curl -k -L -o /tmp/websockify.zip https://github.com/novnc/websockify/archive/v${WEBSOCKIFY_VERSION}.zip \
 && unzip /tmp/websockify.zip -d /usr/local/novnc/ \
 && ln -sf /usr/local/novnc/websockify-${WEBSOCKIFY_VERSION} /usr/local/novnc/noVNC-${NOVNC_VERSION}/utils/websockify \
 && rm -rf /tmp/novnc.zip /tmp/websockify.zip

COPY novnc.sh /usr/local/share
RUN chmod +x /usr/local/share/novnc.sh
ENTRYPOINT ["/usr/local/share/novnc.sh"]

USER ${USERNAME}
WORKDIR /home/${USERNAME}

RUN git clone --recursive https://github.com/tianocore/edk2.git edk2 \
 && (cd edk2 && git checkout --recurse-submodules edk2-stable202208) \
 && make -C edk2/BaseTools/Source/C

ENV PATH="/home/${USERNAME}/osbook/devenv:${PATH}"
RUN mkdir -p /home/${USERNAME}/workspace

RUN git clone https://github.com/kxkx5150/mikanos-build.git osbook
RUN curl -L https://github.com/uchan-nos/mikanos-build/releases/download/v2.0/x86_64-elf.tar.gz \
  | tar xzvf - -C osbook/devenv

RUN chmod +x /home/${USERNAME}/osbook/devenv/buildenv.sh
USER root

COPY ./.setdevenv /root
RUN cat /root/.setdevenv >> /home/${USERNAME}/.bashrc

ENV DISPLAY=host.docker.internal:0

CMD ["/bin/sh", "-c", "echo Container started ; trap \"exit 0\" 15; while sleep 1 & wait $!; do :; done"]